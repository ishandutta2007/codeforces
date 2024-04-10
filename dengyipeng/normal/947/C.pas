var
        n,i,j,k,cnt:longint;
        a:array[1..300000] of longint;
        t:array[1..10000000,0..2] of longint;
        _2:array[0..30] of longint;
procedure put(x,s,i:longint);
var y,k:longint;
begin
        inc(t[x,2]);if i=-1 then exit;
        k:=s div _2[i];
        if t[x,k]=0 then begin inc(cnt); t[x,k]:=cnt; end;
        put(t[x,k],s mod _2[i],i-1);
end;
function find(x,s,i:longint):longint;
var y,k:longint;
begin
        dec(t[x,2]);if i=-1 then exit(0);
        k:=s div _2[i];
        if (t[x,k]=0)or(t[t[x,k],2]=0) then k:=1-k;
        exit(_2[i]*k+find(t[x,k],s mod _2[i],i-1));
end;
begin
        _2[0]:=1; for i:=1 to 30 do _2[i]:=_2[i-1]*2;
        readln(n);
        for i:=1 to n do read(a[i]);
        cnt:=1;
        for i:=1 to n do
        begin read(j); put(1,j,30); end;
        for i:=1 to n do write(find(1,a[i],30) xor a[i],' ');
end.