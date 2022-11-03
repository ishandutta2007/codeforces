program task_1;

{$APPTYPE CONSOLE}
uses Math, SysUtils;
var c: char;
    m,x1,y1,x2,y2: integer;
    ans: array[1..1000]of string;
begin
  readln(c,y1);
  x1:=ord(c)-ord('a')+1;
  readln(c,y2);
  x2:=ord(c)-ord('a')+1;
  y1:=9-y1;
  y2:=9-y2;
  while (y1<>y2)or(x1<>x2)do
    if (x1=x2)and(y1<y2)then begin
      inc(m);
      ans[m]:='D';
      inc(y1);
    end else
    if (x1=x2)and(y1>y2)then begin
      inc(m);
      ans[m]:='U';
      dec(y1);
    end else
    if (y1=y2)and(x1<x2)then begin
      inc(m);
      ans[m]:='R';
      inc(x1);
    end else
    if (y1=y2)and(x1>x2)then begin
      inc(m);
      ans[m]:='L';
      dec(x1);
    end else
    if (y1<y2)and(x1<x2)then begin
      inc(m);
      ans[m]:='RD';
      inc(y1);
      inc(x1);
    end else
    if (y1<y2)and(x1>x2)then begin
      inc(m);
      ans[m]:='LD';
      inc(y1);
      dec(x1);
    end else
    if (y1>y2)and(x1<x2)then begin
      inc(m);
      ans[m]:='RU';
      dec(y1);
      inc(x1);
    end else begin
      inc(m);
      ans[m]:='LU';
      dec(y1);
      dec(x1);
    end;
  writeln(m);
  for x1:=1 to m do
    writeln(ans[x1]);
end.