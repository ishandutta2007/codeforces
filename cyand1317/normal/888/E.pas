program Maximum_Subsequence;

const
   maxn = 35;
   half = 18;

var
   n, m: longint;
   a: array [1 .. maxn] of longint;

   left, right: longint;
   b, c: array [0 .. (1 shl half) - 1] of longint;

   i, j, ans: longint;

procedure process(sz, offs: longint; var x: array of longint);
var
   i, j, sum: longint;
begin
   for i := 0 to (1 shl sz) - 1 do begin
      sum := 0;
      for j := 0 to sz - 1 do
         if (i and (1 shl j)) > 0 then
            sum := (sum + a[offs + j]) mod m;
      x[i] := sum;
   end;
end;

procedure sort(var arr: array of longint; l, r: longint);
var
   m, t, i, j: longint;
begin
   m := arr[l + random(r - l + 1)];
   i := l;
   j := r;
   repeat
      while arr[i] < m do inc(i);
      while arr[j] > m do dec(j);
      if i <= j then begin
         t := arr[i]; arr[i] := arr[j]; arr[j] := t;
         inc(i); dec(j);
      end;
   until i > j;
   if j > l then sort(arr, l, j);
   if i < r then sort(arr, i, r);
end;

begin
   readln(n, m);
   for i := 1 to n do read(a[i]);

   left := n div 2;
   right := n - left;
   process(left, 1, b);
   process(right, left + 1, c);
   randomize;
   sort(b, 0, (1 shl left) - 1);
   sort(c, 0, (1 shl right) - 1);

   if c[0] = c[(1 shl right) - 1] then begin
      writeln(b[(1 shl left) - 1]);
      halt;
   end;

   j := 1;
   ans := 0;
   for i := 0 to (1 shl left) - 1 do begin
      while (b[i] + c[j]) mod m <= (b[i] + c[(j + 1) mod (1 shl right)]) mod m do
         j := (j - 1 + (1 shl right)) mod (1 shl right);
      if ans < (b[i] + c[j]) mod m then
         ans := (b[i] + c[j]) mod m;
   end;

   writeln(ans);
end.