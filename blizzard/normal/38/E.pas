uses Math;
var
   n,i,j : longint;
   s,mi : int64;
   a : array[0..5000,0..2] of int64;
   x,c : array[0..5000] of int64;
procedure qsort(l, r : longint);
var  i, j : longint;
xx,t : int64;
begin
   i := l;
   j := r;
   xx := x[(r+l) div 2];
   repeat
      while x[i] < xx do inc(i);
      while x[j] > xx do dec(j);
      if i <= j then begin
         t := x[i];
         x[i] := x[j];
         x[j] := t;
         t := c[i];
         c[i] := c[j];
         c[j] := t;
         inc(i);
         dec(j);
      end;
   until i > j;
   if i < r then qsort(i, r);
   if l < j then qsort(l, j);
end;
begin
   read(n);
   for i := 1 to n do
      read(x[i],c[i]);
   qsort(1,n);
   for i := 1 to 300000 do
       a[1,1] := a[1,1] + maxlongint;
   a[1,2] := c[1];
   a[1,0] := 1;
   for i := 2 to n do
   begin
      a[i,2] := c[i] + min(a[i-1,1],a[i-1,2]);
      mi := maxlongint;
      s := 0;
      for j := i - 1 downto 1 do
      begin
         s := s + (i - j)*(x[j+1]-x[j]);
         if s + a[j,2] < mi then mi := s + a[j,2];
      end;
      a[i,1] := mi;
   end;
   write(min(a[n,1],a[n,2]));
end.