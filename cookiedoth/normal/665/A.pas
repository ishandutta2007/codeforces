function azaza(sa,fa,sb,fb:integer):boolean;
begin
    if (sb>=fa) or (fb<=sa) then result:=false else result:=true;
end;
var
    a,ta,b,tb,i,h,m,err,ans,t:integer;
    s:string;
begin  
    readln(a,ta);
    readln(b,tb);
    readln(s);
    val(copy(s,1,2),h,err);
    val(copy(s,4,2),m,err);
    if err<>0 then writeln('ololololololo');
    i:=300;
    ans:=0;
    t:=h*60+m;
    while i<=1439 do
    begin
        if azaza(t,t+ta,i,i+tb) then inc(ans);
        inc(i,b);
    end;
    write(ans);
end.