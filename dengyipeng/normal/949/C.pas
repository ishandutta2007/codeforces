uses math;
var
        n,m,h,i,j,k,x,y,em,num,top,mx,id:longint;
        a,e,last,next,low,dfn,flag,d,home,siz:array[1..200000] of longint;
        bz:array[1..100000] of boolean;
procedure insert(x,y:longint);
begin
        inc(em); e[em]:=y; next[em]:=last[x]; last[x]:=em;
end;
procedure dg(x:longint);
var i,j,y:longint;
begin
        inc(num); dfn[x]:=num; low[x]:=num;
        inc(top); d[top]:=x;  flag[x]:=1;
        i:=last[x];
        while i>0 do
        begin
                y:=e[i];
                if dfn[y]=0 then
                begin
                        dg(y);
                        low[x]:=min(low[x],low[y]);
                end else if flag[y]=1 then low[x]:=min(low[x],dfn[y]);
                i:=next[i];
        end;
        if dfn[x]=low[x] then
        begin
                while i<>x do
                begin
                        i:=d[top]; dec(top);
                        home[i]:=x; inc(siz[x]);
                        flag[i]:=0;
                end;
        end;
end;
begin
        readln(n,m,h);
        for i:=1 to n do read(a[i]);
        for i:=1 to m do
        begin
                readln(x,y);
                if (a[x]+1) mod h=a[y] then insert(x,y);
                if (a[y]+1) mod h=a[x] then insert(y,x);
        end;
        num:=0; top:=0;
        for i:=1 to n do if dfn[i]=0 then
        begin top:=0;dg(i); end;

        fillchar(bz,sizeof(bz),true);
        for x:=1 to n do
        if home[x]<>0 then
        begin
                i:=last[x];
                while i>0 do
                begin
                        y:=e[i];
                        if home[x]<>home[y] then
                        begin
                                bz[home[x]]:=false;
                                break;
                        end;
                        i:=next[i];
                end;
        end;
        mx:=maxlongint;
        for i:=1 to n do
        if (home[i]<>0)and(dfn[i]=low[i])and(bz[i])and(siz[i]<mx) then
        begin
                mx:=siz[i]; id:=i;
        end;
        writeln(mx);
        for i:=1 to n do if home[i]=id then write(i,' ');

end.