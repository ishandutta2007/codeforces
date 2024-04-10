var n, a, b, i, ka, kb:integer;
BEGIN
  readln(n, a, b);
  ka:=0;
  while(n>=0)and(n mod b<>0)do
    begin
      n:=n-a;
      ka:=ka+1;
    end;
  if(n<0)
    then writeln('NO')
    else begin
           writeln('YES');
           kb:=n div b;
           writeln(ka, ' ', kb);
         end;
END.