var
   n : longint;
begin
   read(n);
   if n = 2 then
   begin
      writeln('1');
      halt(0);
   end;
    if n = 3 then
   begin
      writeln('1 2');
      writeln('2 11');
      halt(0);
   end;
    if n = 4 then
   begin
      writeln('1 2 3');
      writeln('2 10 12');
      writeln('3 12 21');
      halt(0);
   end;
   if n = 5 then
   begin
      writeln('1 2 3 4');
      writeln('2 4 11 13');
      writeln('3 11 14 22');
      writeln('4 13 22 31');
      halt(0);
   end;
    if n = 6 then
   begin
      writeln('1 2 3 4 5');
      writeln('2 4 10 12 14');
      writeln('3 10 13 20 23');
      writeln('4 12 20 24 32');
      writeln('5 14 23 32 41');
      halt(0);
   end;
    if n = 7 then
   begin
      writeln('1 2 3 4 5 6');
      writeln('2 4 6 11 13 15');
      writeln('3 6 12 15 21 24');
      writeln('4 11 15 22 26 33');
      writeln('5 13 21 26 34 42');
      writeln('6 15 24 33 42 51');
      halt(0);
   end;
    if n = 8 then
   begin
      writeln('1 2 3 4 5 6 7');
      writeln('2 4 6 10 12 14 16');
      writeln('3 6 11 14 17 22 25');
      writeln('4 10 14 20 24 30 34');
      writeln('5 12 17 24 31 36 43');
      writeln('6 14 22 30 36 44 52');
      writeln('7 16 25 34 43 52 61');
      halt(0);
   end;
   if n = 9 then
   begin
      writeln('1 2 3 4 5 6 7 8');
      writeln('2 4 6 8 11 13 15 17');
      writeln('3 6 10 13 16 20 23 26');
      writeln('4 8 13 17 22 26 31 35');
      writeln('5 11 16 22 27 33 38 44');
      writeln('6 13 20 26 33 40 46 53');
      writeln('7 15 23 31 38 46 54 62');
      writeln('8 17 26 35 44 53 62 71');
      halt(0);
   end;
   if n = 10 then
   begin
      writeln('1 2 3 4 5 6 7 8 9');
      writeln('2 4 6 8 10 12 14 16 18');
      writeln('3 6 9 12 15 18 21 24 27');
      writeln('4 8 12 16 20 24 28 32 36');
      writeln('5 10 15 20 25 30 35 40 45');
      writeln('6 12 18 24 30 36 42 48 54');
      writeln('7 14 21 28 35 42 49 56 63');
      writeln('8 16 24 32 40 48 56 64 72');
      writeln('9 18 27 36 45 54 63 72 81');
      halt(0);
   end;
end.