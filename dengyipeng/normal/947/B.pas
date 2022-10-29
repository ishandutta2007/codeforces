uses math;
var
        n,i,l,r,mid:longint;
        k:int64;
        s,x,y,p:array[0..100001] of int64;
        c:array[0..100001] of longint;
begin
        readln(n);
        for i:=1 to n do read(x[i]);
        for i:=1 to n do
        begin
                read(y[i]);
                s[i]:=s[i-1]+y[i];
        end;
        for i:=1 to n do
        begin
                x[i]:=x[i]+s[i-1];
                l:=i;r:=n;
                while l<r-1 do
                begin
                        mid:=(l+r) div 2;
                        if x[i]<s[mid] then r:=mid-1
                        else l:=mid;
                end;
                if x[i]>=s[r] then l:=r;
                if x[i]<s[l] then dec(l);
                inc(c[i]); dec(c[l+1]);
                p[l+1]:=p[l+1]+min(x[i]-s[l],y[l+1]);
        end;
        k:=0;
        for i:=1 to n do
        begin
                k:=k+c[i];
                write(k*y[i]+p[i],' ');
        end;
end.