program Program56;
var
n,i,j,a,b,c:Integer;
function Prost(x:Integer):Boolean;
var
ii:Integer;
begin
    if x=1 then
    begin
        Result:=false;
        exit;
    end;
    if x=2 then
    begin
        Result:=true;
        exit;
    end;
    for ii:=2 to trunc(sqrt(x))+1 do
    begin
        if (x mod ii)=0 then
        begin
            result:=false;
            exit;
        end;
    end;
    result:=true;
end;
function NearProst(x:Integer):Integer;
var
    ii:Integer;
    b:Boolean;
begin
    for ii:=x downto 2 do
    begin
        b:=prost(ii);
        if b then 
        begin
            Result:=ii;
            Break;
        end;
    end;
end;
begin
    Readln(n);
    a:=nearprost(n);
    if n=a then
    begin
        Writeln(1);
        Writeln(n);
        Halt(0);
    end;
    if a+1=n then a:=nearprost(a-1);
    if prost(n-a) then
    begin
        Writeln(2);
        Writeln(a,' ',n-a);
        exit;
    end;
    for i:=2 to n-a do
    begin
        b:=i;
        c:=n-a-i;
        if (prost(b)) and (prost(c)) then
        begin
            Writeln(3);
            Writeln(a,' ',b,' ',c);
            Halt(0);
        end;
    end;
end.