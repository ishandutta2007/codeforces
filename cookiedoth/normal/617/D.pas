program taskd;
var
    x,y:array[1..3] of integer;
    i:integer;
procedure duo(n,m,l:Integer);
var
    x1,y1,x2,y2:integer;
    g:Boolean;
begin
    g:=false;
    if x[n]<x[m] then begin x1:=x[n]; x2:=x[m]; end;
    if x[n]>=x[m] then begin x1:=x[m]; x2:=x[n]; end;
    if y[n]<y[m] then begin y1:=y[n]; y2:=y[m]; end;
    if y[n]>=y[m] then begin y1:=y[m]; y2:=y[n]; end;
    if (x[l]=x1) and (y[l]>=y1) and (y[l]<=y2) then g:=true;
    if (x[l]=x2) and (y[l]>=y1) and (y[l]<=y2) then g:=true;
    if (y[l]=y1) and (x[l]>=x1) and (x[l]<=x2) then g:=true;
    if (y[l]=y2) and (x[l]>=x1) and (x[l]<=x2) then g:=true;
    if (g) then begin write(2); halt(0); end;
end;
begin
    for i:=1 to 3 do
        readln(x[i],y[i]);
    if (x[1]=x[2]) and (x[2]=x[3]) then begin write(1); halt(0); end;
    if (y[1]=y[2]) and (y[2]=y[3]) then begin write(1); halt(0); end;
    duo(1,2,3);
    duo(2,3,1);
    duo(1,3,2);
    write(3);
end.