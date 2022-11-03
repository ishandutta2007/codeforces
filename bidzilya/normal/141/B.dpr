{$APPTYPE CONSOLE}

var
  c,x,y,a,l:integer;
  x1,x2,y1:real;

procedure prov;
begin
  if (x>x1)and(x<x2)and(y>y1)and(y<y1+a)then begin write(c); halt; end;
end;

begin
  read(a,x,y);
  x2:=a/2;
  x1:=-x2;
  if (y>0)and(y<a)and(x>x1)and(x<x2)then begin write(1); halt; end;
  c:=2; l:=1;
  y1:=a;
  while (y>y1)do begin
    prov;
    if (l mod 2=0)then begin
      x1:=0; x2:=a; inc(c); prov;
    end;
    if (x1=0)then begin x2:=a/2; x1:=-x2; end else
    begin x1:=-a; x2:=0; end;
    y1:=y1+a;
    inc(l);
    inc(c);
  end;
  write(-1);
end.