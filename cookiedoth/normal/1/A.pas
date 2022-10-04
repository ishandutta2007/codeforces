program Area;
var
n,m,a,x,y:Int64;
begin
    Readln(n,m,a);
    if (n mod a)=0 then x:=(n div a)
    else x:=(n div a)+1;
    if (m mod a)=0 then y:=(m div a)
    else y:=(m div a)+1;
    Writeln(x*y);
end.