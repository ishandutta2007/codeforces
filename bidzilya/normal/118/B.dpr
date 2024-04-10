program Project1;

{$APPTYPE CONSOLE}

uses
  SysUtils;
const dx: array[1..4]of integer = (-1,0,0,1);
      dy: array[1..4]of integer = (0,1,-1,0);
var n,i,j: integer;
    m: array[1..100,1..100]of integer;
    qx,qy,cl: array[1..1000]of integer;

procedure go(c,y,x: integer);
var ps,pe,xx,yy: integer;
begin
  m[y,x]:=c;
  ps:=1;pe:=1;
  qy[1]:=y;qx[1]:=x;cl[1]:=c;
  while (ps<=pe)do begin
    x:=qx[ps];
    y:=qy[ps];
    c:=cl[ps];
    if (c<0)then break;
    for i:=1 to 4 do begin
      xx:=dx[i]+x;
      yy:=dy[i]+y;
      if (xx>0)and(xx<=2*n+1)and
         (yy>0)and(yy<=2*n+1)and
         (m[yy,xx]=-1)then begin
          inc(pe);
          qx[pe]:=xx;
          qy[pe]:=yy;
          cl[pe]:=c-1;
          m[yy,xx]:=c-1;
         end;
    end;
    inc(ps);
  end;
end;
var ans: array[1..200]of string;
begin
  read(n);
  for i:=1 to 2*n+1 do
    for j:=1 to 2*n+1 do
      m[i,j]:=-1;
  go(n,n+1,n+1);
  for i:=1 to 2*n+1 do begin
    ans[i]:='';
    for j:=1 to 2*n+1 do begin
      if (m[i,j]=-1)then
        ans[i]:=ans[i]+' '
      else
        ans[i]:=ans[i]+inttostr(m[i,j]);
      ans[i]:=ans[i]+' ';
    end;
  end;
  for i:=1 to 2*n+1 do begin
    while (ans[i][length(ans[i])]=' ')do
      delete(ans[i],length(ans[i]),1);
    writeln(ans[i]);
  end;
end.