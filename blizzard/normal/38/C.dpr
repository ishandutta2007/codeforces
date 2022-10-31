var
   a : array[0..200] of longint;
   min,i,n,j,l,kol : longint;
begin
   read(n,l);
   for i := 1 to n do
      read(a[i]);
   min := 0;
   for j := l to 101 do
   begin
      kol := 0;
      for i := 1 to n do
         kol := kol + (a[i] div j);
      if (min < j * kol) and (kol <> 0) then min := j * kol;
   end;
   write(min);
end.