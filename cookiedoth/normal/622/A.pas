program TaskA;
var
    k,i,x:int64;
begin
    read(x);
    i:=0; k:=0;
    while i+k<x do begin k:=k+i; i:=i+1; end;
    write(x-k);
end.