var
   n,m,kol,i,j : longint;
   a,b : array[0..1000] of longint;
begin
   read(n,m);
   for i := 1 to m do
      read(a[i],b[i]);
   for i := 1 to n do
   begin
      kol := 0;
      for j := 1 to m do
         if (i >= a[j]) and (i <= b[j]) then inc(kol);
      if kol <> 1 then
      begin
         write(i,' ',kol);
         halt(0);
      end;
   end;
   write('OK');
end.