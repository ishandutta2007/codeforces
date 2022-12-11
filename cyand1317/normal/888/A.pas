program Local_Extrema;

const
   maxn = 1003;

var
   n: longint;
   a: array [1 .. maxn] of longint;

   i, ans: longint;

begin
   readln(n);
   for i := 1 to n do read(a[i]);

   ans := 0;
   for i := 2 to n - 1 do
      if ((a[i] > a[i - 1]) and (a[i] > a[i + 1])) or ((a[i] < a[i - 1]) and (a[i] < a[i + 1])) then
         inc(ans);

   writeln(ans);
end.