program TaskA;
var
    p,i,x,ans,j:Integer;
    b:Boolean;
begin
    Readln(p);
    ans:=0;
    for i:=1 to p-1 do
    begin
        x:=1;
        b:=true;
        for j:=1 to p-2 do
        begin
            x:=x*i;
            x:=x mod p;
            if x=1 then
            begin
                b:=false;
                break;
            end;
        end;
        x:=x*i;
        x:=x mod p;
        if (x<>1) then
            b:=false;
        if b then inc(ans);
    end;
    Writeln(ans);
end.