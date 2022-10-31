var
   i,n,j,kol : longint;
   s :array[0..1000] of string;
  f : boolean;
begin
   readln(n);
   for i := 1 to n do
      readln(s[i]);
   kol := 0;
   for i := 1 to n do
   begin
       f := true;
      for j := i + 1 to n do
      if s[i] = s[j] then f := false;
      if f then inc(kol);
   end;
   write(kol);
end.