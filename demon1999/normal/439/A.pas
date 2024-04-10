var a:array[1..301]of longint;
    n,i,j,k,su,d:longint;
begin
readln(n,d);
su:=(n-1)*10;
for i:=1 to n do begin
    read(a[i]);inc(su,a[i]);
    end;
if su>d then begin writeln(-1);halt;end;
writeln((d-(su-(n-1)*10))div 5);
end.