var
   tek, n : int64;
begin                           {
   assign(input,'input.txt');
   assign(output, 'output.txt');
   reset(input);
   rewrite(output);            }
   readln(n);
   tek := 5;
   while n > tek do
   begin
      n := n - tek;
      tek := tek * 2;
   end;
   if n <= tek div 5 then write('Sheldon')
     else
        if n <= (tek div 5)*2 then write('Leonard')
           else  if n <= (tek div 5)*3 then write('Penny')
           else
               if n <= (tek div 5)*4 then write('Rajesh')
              else
               if n <= (tek div 5)*5 then write('Howard');
              close(output);
end.