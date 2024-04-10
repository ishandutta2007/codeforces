var a,st: array[1..200005] of longint;
    n,i,sz: longint;
begin
sz:=0;
readln(n);
for i:=0 to n-1 do
begin
    read(a[i]);
    st[sz] := a[i];
    sz := sz + 1;
    while (sz>=2) and(st[sz-1]=st[sz-2]) do
    begin
    sz:=sz-1;
    st[sz-1] := st[sz-1]+1;
    end;
end;
writeln(sz);
for i:=0 to sz-1 do write(st[i],' ');
end.