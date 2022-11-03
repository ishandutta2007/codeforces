program Task1;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var n,m,i,j,t: integer;
    x,y: array[1..3]of integer;
    s: string;
begin
  readln(n,m);
  t:=0;
  for i:=1 to n do begin
    readln(s);
    for j:=1 to m do
      if (s[j]='*')then begin
        inc(t);
        x[t]:=j;
        y[t]:=i;
      end;
  end;
  if (y[1]=y[3])then begin
    t:=y[2];y[2]:=y[3];y[3]:=t;
    t:=x[2];x[2]:=x[3];x[3]:=t;
  end else
  if (y[2]=y[3])then begin
    t:=y[1];y[1]:=y[3];y[3]:=t;
    t:=x[1];x[1]:=x[3];x[3]:=t;
  end;
  if (x[3]=x[2])then
    write(y[3],' ',x[1])
  else
    write(y[3],' ',x[2]);

end.