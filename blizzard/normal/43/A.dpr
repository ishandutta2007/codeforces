{$h+}
var
   n, i, kol : longint;
   s : array[0..1000] of string;
begin
   readln(n);
   for i := 1 to n do
      readln(s[i]);
   kol := 0;
   for i := 1 to n do
      if s[i] = s[1] then inc(kol);
   if kol > n div 2 then writeln(s[1]) else
   begin
      for i := 2 to n do
         if s[i] <> s[1] then
         begin
            writeln(s[i]) ;
            halt(0);
         end;
   end;
end.