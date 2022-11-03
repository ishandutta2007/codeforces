program Project1;

{$APPTYPE CONSOLE}

uses
  SysUtils;
const name: array[1..5]of string = ('Sheldon','Leonard','Penny','Rajesh','Howard');
var cnt,q: array[1..5]of integer;
    l,r,t,m,i,j,n: integer;
begin
  for i:=1 to 5 do begin
    q[i]:=i;
    cnt[i]:=1;
  end;
  read(n);
  l:=1;r:=5;
  while (true)do begin
    t:=q[l];
    m:=cnt[l];
    if (n<=m)then begin
      write(name[t]);
      break;
    end;
    dec(n,m);
    inc(l);
    inc(r);
    if (r=6)then
      r:=1;
    if (l=6)then
      l:=1;
    q[r]:=t;
    cnt[r]:=2*m;
  end;

end.