uses math;
var
        i:longint;
        s:array[0..100005] of int64;
        t1,t2,b,a,n,d:int64;
function sum(l,r:int64):int64;
begin
        exit(s[min(n,r)]-s[max(1,l)-1]);
end;
begin
        readln(n,d,b);
        for i:=1 to n do
        begin
                read(a);
                s[i]:=s[i-1]+a;
        end;
        t1:=0;t2:=0;
        for i:=1 to n div 2 do
        begin
                if sum(1,i+i*d)>=(t1+1)*b then inc(t1);
                if sum(n-i+1-i*d,n)>=(t2+1)*b then inc(t2);
        end;
        writeln(n div 2-min(t1,t2));
end.