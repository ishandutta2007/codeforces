program TaskB;
var
    min,k,h,m:integer;
    s,hh,mm:string;
function inttostr(int:Integer):String;
begin
    Str(int,Result);
end;
function strtoint(str:string):integer;
var
    err:integer;
begin
    val(str,result,err);
end;
begin
    readln(s);
    readln(k);
    min:=0;
    min:=min+strtoint(copy(s,1,2))*60+strtoint(copy(s,4,2));
    min:=min+k;
    m:=min mod 60;
    h:=min div 60;
    h:=h mod 24;
    hh:=inttostr(h); mm:=inttostr(m);
    if h<10 then hh:='0'+hh; if m<10 then mm:='0'+mm;
    write(hh+':'+mm);
end.