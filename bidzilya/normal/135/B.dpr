{$APPTYPE CONSOLE}

type point = record
  x,y:integer;
end;
Arr = array[1..4]of integer;
PArr = ^Arr;
var
  a:array[1..8]of point;
  rect,sq:Arr;
  lsq,lrect,i:integer;

function paral(P:PArr):boolean;
var
  dx1,dy1,dx2,dy2,dx3,dy3,dx4,dy4:integer;
begin
  dx1:=a[p^[2]].x-a[p^[1]].x;
  dx2:=a[p^[3]].x-a[p^[2]].x;
  dx3:=a[p^[4]].x-a[p^[3]].x;
  dx4:=a[p^[1]].x-a[p^[4]].x;

  dy1:=a[p^[2]].y-a[p^[1]].y;
  dy2:=a[p^[3]].y-a[p^[2]].y;
  dy3:=a[p^[4]].y-a[p^[3]].y;
  dy4:=a[p^[1]].y-a[p^[4]].y;
  paral:=(dx1*dx2+dy1*dy2=0)and(dx2*dx3+dy2*dy3=0)and(dx3*dx4+dy3*dy4=0)and(dx4*dx1+dy4*dy1=0);
end;

function r2(i1,i2:integer):integer;
begin
  r2:=sqr(a[i1].x-a[i2].x)+sqr(a[i1].y-a[i2].y);
end;

function prov(P:PArr;k:integer):boolean;
var
  i,tmp,j,l:integer;
  t:Arr;

begin
  prov:=false;
  for i:=1 to 4 do
    t[i]:=P^[i];
  for i:=2 to 3 do
    for j:=i+1 to 4 do
      if t[j]<t[i]then
      begin
        tmp:=t[i];
        t[i]:=t[j];
        t[j]:=tmp;
      end;

  while (true)do
  begin
    if paral(@t)then
      if (k=0)or((k=1)and(r2(t[1],t[2])=r2(t[2],t[3])))then
      begin
        prov:=true;
        exit;
      end;

    i:=3;
    while (i>1)and(t[i]>t[i+1])do
      dec(i);
    if i=1 then
      break;
    j:=4;
    while (j>1)and(t[j]<t[i]) do
      dec(j);
    if j=1 then
      break;
    tmp:=t[i];
    t[i]:=t[j];
    t[j]:=tmp;
    for l:=i+1 to 3 do
      for j:=l+1 to 4 do
        if t[j]<t[l]then
        begin
          tmp:=t[l];
          t[l]:=t[j];
          t[j]:=tmp;
        end;
  end;
end;

procedure rec(v:integer);
var
  i:integer;
begin
  if (v=9)then
  begin
    if (prov(@sq,1))and(prov(@rect,0))then
    begin
      writeln('YES');
      for i:=1 to lsq do
        write(sq[i],' ');
      writeln;
      for i:=1 to lrect do
        write(rect[i],' ');
      halt;
    end;
    exit;
  end;
  if (lsq<4)then
  begin
    inc(lsq);
    sq[lsq]:=v;
    rec(v+1);
    dec(lsq);
  end;
  if (lrect<4)then
  begin
    inc(lrect);
    rect[lrect]:=v;
    rec(v+1);
    dec(lrect);
  end;
end;

begin
  lsq:=0;
  lrect:=0;
  for i:=1 to 8 do
    read(a[i].x,a[i].y);
  rec(1);
  writeln('NO');
end.