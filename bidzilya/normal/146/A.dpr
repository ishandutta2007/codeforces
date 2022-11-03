program task_1;
{$APPTYPE CONSOLE}
var ch,i,n,sum1,sum2:integer;
    c:char;

begin
  sum1:=0; sum2:=0;
  readln(n);
  for i:=1 to n do begin
    read(c);
    ch:=ord(c)-ord('0');
    if (i<=n div 2)then sum1:=sum1+ch else
      sum2:=sum2+ch;
    if (ch<>4)and(ch<>7)then begin
      write('NO');
      halt;
    end;
  end;
  if (sum1<>sum2)then write('NO')else
    write('YES');
end.