uses math;
var
        n,i,j,sn,mi,ans:longint;
        k,t1,t2:int64;
        ss:array[1..1000000] of int64;
        vis:array[1..1000000] of boolean;
begin
        readln(n);
        for i:=2 to n do
        begin
                if not vis[i] then begin inc(sn);ss[sn]:=i; end;
                for j:=1 to sn do
                begin
                        t1:=ss[j];t2:=i;
                        if t1*t2>n then break;
                        vis[ss[j]*i]:=true;
                        if i mod ss[j]=0 then break;
                end;
        end;
        for i:=sn downto 1 do if n mod ss[i]=0 then
        begin mi:=max(n-ss[i]+1,ss[i]+1); break; end;
        ans:=maxlongint;
        for i:=1 to sn do
        begin
                k:=((mi-1) div ss[i]+1)*ss[i];
                if k>n then continue;
                ans:=min(ans,max(k-ss[i]+1,ss[i]+1));
        end;
        writeln(ans);
end.