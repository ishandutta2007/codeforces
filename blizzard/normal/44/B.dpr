var
   i,n,j,kol,a,b,c : longint;
begin
   read(n, a, b, c);
   kol := 0;
   for i := 0 to a do
   begin
     if (i mod 2 = 1) then continue;
     for j := 0 to c do
       if (i / 2 + 2 * j <= n) then
         if (n - i div 2 - 2 * j <= b) then inc(kol);
   end;
   write(kol);
end.