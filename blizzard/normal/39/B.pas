var
   j,i,n,tek : longint;
   a,b : array[0..1000] of longint;
begin
j := 0;
   read(n);
   for i := 1 to n do
      read(a[i]);
   tek := 1;
   for i := 1 to n do
      if a[i] = tek then
      begin
         inc(j);
         b[j] := 2000 + i;
         inc(tek);
      end;
   writeln(j);
   for i := 1 to j do
      write(b[i],' ');
end.