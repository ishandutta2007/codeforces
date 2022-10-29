uses math;
var
        s,t:ansistring;
        c1,c2,v1,v2:array[0..100000] of longint;
        que,i,x1,y1,x2,y2,l1,r1,l2,r2,ans:longint;
begin
        readln(s);
        for i:=1 to length(s) do
        begin
                c1[i]:=c1[i-1]; if s[i]<>'A' then inc(c1[i]);
                v1[i]:=v1[i-1]+1; if s[i]<>'A' then v1[i]:=0;
        end;
        readln(t);
        for i:=1 to length(t) do
        begin
                c2[i]:=c2[i-1]; if t[i]<>'A' then inc(c2[i]);
                v2[i]:=v2[i-1]+1; if t[i]<>'A' then v2[i]:=0;
        end;
        readln(que);
        while que>0 do
        begin
                dec(que);readln(l1,r1,l2,r2);
                x1:=c1[r1]-c1[l1-1];y1:=min(r1-l1+1,v1[r1]);
                x2:=c2[r2]-c2[l2-1];y2:=min(r2-l2+1,v2[r2]);
                ans:=1;
                if (x1>x2)or((x2-x1)mod 2>0)or(y1<y2) then ans:=0;
                if (x1=x2)and((y2-y1)mod 3<>0) then ans:=0;
                if (x1=0)and(x2>0)and(y1=y2) then ans:=0;
                write(ans);
        end;
end.