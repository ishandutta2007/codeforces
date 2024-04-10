program project1;

{$apptype console}

uses Math, SysUtils;
const dx: array[1..5]of integer = (0,-1,0,0,1);
      dy: array[1..5]of integer = (0,0,1,-1,0);
var map: array[-222..222,-222..222]of boolean;
    i,j,py,px,x,y: integer;
    s: string;

function check: boolean;
var i,nx,ny: integer;
begin
  for i:=1 to 5 do begin
    nx:=x+dx[i];ny:=y+dy[i];
    if ((nx<>px)or(ny<>py))and(map[ny,nx])then begin
      check:=true;
      exit;
    end;
  end;
  check:=false;
end;

begin
  fillchar(map,sizeof(map),false);
  readln(s);
  x:=0;y:=0;
  map[0,0]:=true;
  for i:=1 to length(s)do begin
    py:=y;px:=x;
    if (s[i]='L')then
      dec(x)
    else
    if (s[i]='R')then
      inc(x)
    else
    if (s[i]='D')then
      dec(y)
    else
      inc(y);
    if check then begin
      writeln('BUG');
      halt;
    end;
    map[y,x]:=true;
  end;
  writeln('OK');
end.