program Task1;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var ans,n,i,j: integer;
    x,y: array[1..3000]of integer;
    b: array[-1000..1000,-1000..1000]of boolean;
    tx,ty: integer;
begin
  read(n);
  for i:=-1000 to 1000 do
    for j:=-1000 to 1000 do
      b[i,j]:=false;
  for i:=1 to n do begin
    read(x[i],y[i]);
    b[x[i],y[i]]:=true;
  end;
  for i:=1 to n do
    for j:=i+1 to n do begin
      tx:=x[i]+x[j];
      ty:=y[i]+y[j];
      if (tx mod 2=0)and(ty mod 2=0)and(b[tx div 2,ty div 2])then
        inc(ans);
    end;
  write(ans);
end.