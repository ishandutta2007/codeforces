var
   sq : array[-10..10] of string;
   n : array[-10..10] of longint;
   s : string;
   i,j,k,q : longint;
begin
   for i := -10 to 10 do
      n[i] := 0;
   readln(n[1],n[2],n[3],n[4],n[5]);
   readln(k);
   sq[1] := 'S';
   sq[2] := 'M';
   sq[3] := 'L';
   sq[4] := 'XL';
   sq[5] := 'XXL';
   for i := 1 to k do
   begin
      readln(s);
      if s = 'S' then j := 1;
      if s = 'M' then j := 2;
      if s = 'L' then j := 3;
      if s = 'XL' then j := 4;
      if s = 'XXL' then j := 5;
      if n[j] > 0 then
      begin
         writeln(s);
         dec(n[j]);
         continue;
      end;
      for q := 1 to 4 do
      begin
         if n[j+q] > 0 then
         begin
            writeln(sq[j+q]);
            dec(n[j+q]);
            break;
         end;
         if n[j-q] > 0 then
         begin
            writeln(sq[j-q]);
            dec(n[j-q]);
            break;
         end;
      end;
   end;
end.