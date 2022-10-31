{$APPTYPE CONSOLE}
var
   n,m,i,j,k : longint;
   c : array[0..1000,0..1000] of longint;
begin
   read(n,m);
   if (n = 1) and (m = 1) then
   begin
      write('1');
      halt(0);
   end;
    if (n = 1) and (m = 4) then
   begin
      write('2 4 1 3');
      halt(0);
   end;
    if (n = 4) and (m = 1) then
   begin
      writeln('2');
      writeln('4');
      writeln('1');
      writeln('3');
      halt(0);
   end;
   if (n * m <= 4) then
   begin
      write('-1');
      halt(0);
   end;
   if (n = 2) and (m = 3) then
   begin
      writeln('3 6 2');
      writeln('5 1 4');
      halt(0);
   end;
   if (n = 3) and (m = 2) then
   begin
      writeln('3 5');
      writeln('6 1');
      writeln('2 4');
      halt(0);
   end;
   k := 1;
   for i := 1 to n do
      for j := 1 to m do
         if ((i+j) mod 2 = 0) then
         begin
            c[i,j] := k;
            inc(k);
         end;
   for i := 1 to n do
      for j := 1 to m do
         if ((i+j) mod 2 = 1) then
         begin
            c[i,j] := k;
            inc(k);
         end;
   for i := 1 to n do
   begin
      for j := 1 to m do
         write(c[i,j],' ');
      writeln;
   end;
end.