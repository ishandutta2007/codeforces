program TaskD;
var
a:array[1..99999] of Int64;
stack:array[0..99999] of Int64;
left,right:array[1..99999] of Int64;
i,j:Integer;
last,this,n,q:Int64;
lt,rt,l,r:Int64;
ans,sz:Int64;
begin
    Readln(n,q);
    Read(last);
    for i:=1 to n-1 do
    begin
        Read(this);
        a[i]:=abs(this-last);
        last:=this;
    end;
    sz:=0;
    stack[0]:=0;
    for i:=1 to n-1 do
    begin
        while ((sz>0) and (a[stack[sz]] <a[i])) do
            dec(sz);
        left[i]:=stack[sz]+1;
        inc(sz);
        stack[sz]:=i;
    end;
    for i:=0 to 99999 do stack[i]:=0;
    sz:=0;
    stack[0]:=n;
    for i:=n-1 downto 1 do
    begin
        while ((sz>0) and (a[stack[sz]] <= a[i])) do
            dec(sz);
        right[i]:=stack[sz]-1;
        inc(sz);
        stack[sz]:=i;
    end;
    for i:=1 to q do
    begin
        Readln(lt,rt);
        dec(rt);
        ans:=0;
        for j:=lt to rt do
        begin
            if left[j]<lt then l:=lt
            else l:=left[j];
            if right[j]>rt then r:=rt
            else r:=right[j];
            inc(ans,(j-l+1)*(r-j+1)*a[j]);
        end;
        Writeln(ans);
    end;
end.