var
   n,i,s,a,b : longint;
   d : array[0..1000] of longint;
begin
   read(n);
   for i := 1 to n-1 do
      read(d[i]);
   read(a,b);
   s := 0;
   for i := a to b - 1 do
      s := s + d[i];
   write(s);
end.