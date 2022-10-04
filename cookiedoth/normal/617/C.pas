var
n,x1,y1,x2,y2,x,y:int64;
i,j:Integer;
max,min:int64;
dis:array[1..2,1..2000] of int64;
begin
    Readln(n,x1,y1,x2,y2);
    for i:=1 to n do
    begin
        Readln(x,y);
        dis[1,i]:=abs(x1-x)*abs(x1-x)+abs(y1-y)*abs(y1-y);
        dis[2,i]:=abs(x2-x)*abs(x2-x)+abs(y2-y)*abs(y2-y);   
    end;
    min:=2000000000000000000;
    for i:=1 to n do
    begin
        max:=0;
        for j:=1 to n do
        begin
            if dis[1,j]>dis[1,i] then
            begin
                if dis[2,j]>max then max:=dis[2,j];
            end;
        end;
        if dis[1,i]{*dis[1,i]}+{max*}max<min then min:={dis[1,i]*}dis[1,i]+{max*}max;
    end;
    for i:=1 to n do
    begin
        max:=0;
        for j:=1 to n do
        begin
            if dis[2,j]>dis[2,i] then
            begin
                if dis[1,j]>max then max:=dis[1,j];
            end;
        end;
        if dis[2,i]{*dis[1,i]}+{max*}max<min then min:={dis[1,i]*}dis[2,i]+{max*}max;
    end;
    Writeln(min);
end.