program Task_A;
var
hor,ver: array[1..50] of Boolean;
n,i,h,v:Integer;
begin
    Readln(n);
    for i:=1 to 50 do
    begin
        hor[i]:=false;
        ver[i]:=false;
    end;
    for i:=1 to n*n do
    begin
        Readln(h,v);
        if (hor[h]=false) and (ver[v]=false) then
        begin
            hor[h]:=true;
            ver[v]:=true;
            Write(i,' ');
        end;
    end;
end.