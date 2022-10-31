var
   ans,i,n,tek,min,j,kol1 : longint;
   c : array[0..3000] of char;
begin
   readln(n);
   for i := 1 to n do
      read(c[i]);
   kol1 := 0;
   for i := 1 to n do
      if c[i] = 'H' then inc(kol1);
   ans := maxlongint;
   for i := 1 to n do
      c[n+i] := c[i];
   min := maxlongint;
   for i := 1 to n do
   begin
      tek := 0;
      for j := i to i + kol1 - 1 do
         if (c[j] <> 'H') then
            inc(tek);
      if tek < min then min := tek;
   end;
   writeln(min);
end.