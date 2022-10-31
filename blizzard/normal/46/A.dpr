var
   i,j,n,tek : longint;
   a : array[0..10000] of longint;
begin
   read(n);
   tek := 1;
   for i := 1 to n-1 do
   begin
      tek := tek + i;
      if tek > n then tek := tek - n;
      write(tek,' ');
   end;
end.