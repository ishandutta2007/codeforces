var a,n,k,i:longint;
begin
readln(n);k:=0;a:=1;
for i:=1 to n-1 do begin
    inc(k);
    a:=(a+k)mod n;
    if a=0 then a:=n;
    write(a,' ');
    end;
end.