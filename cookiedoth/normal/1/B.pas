program Table;
function Func(s:String):Boolean;
var
aaa,p:Integer;
begin
    aaa:=0;
    for p:=1 to length(s) do
        if ord(s[p])>64 then inc(aaa);
    if (ord(s[2])<65) and (aaa>=2) then Result:=true
    else Result:=false;
end;
var
r,c,cpos,n,i,j,co,q:Integer;
ans:array[1..100000] of String;
s:String;
rs,cs:String;
s1,s2,s0:String;
error,leng:Integer;
begin
    Readln(n);
    for i:=1 to n do
    begin
        Readln(s);
        if Func(s) then 
        begin
            for j:=1 to length(s) do
                if s[j]='C' then cpos:=j;
            rs:=copy(s,2,cpos-2);
            cs:=copy(s,cpos+1,length(s)-cpos);
            Val(rs,r,error);
            Val(cs,c,error);
            s0:='';
            while (c>0) do
            begin
               { s0:=s0+chr(64+(c mod 26));
                if c=(c mod 26) then c:=0
                else c:=(c div 26);}
                s0:=s0+chr(65+((c-1) mod 26));
                c:=((c-1) div 26);
            end;
            leng:=length(s0);
            s1:='';
            for j:=1 to leng do
                s1:=s0[j]+s1;
            Str(r,s2);
            ans[i]:=s1+s2;
        end
        else
        begin
            for j:=1 to length(s) do begin
                if ord(s[j])<65 then begin cpos:=j; Break; end; end;   
            s1:=copy(s,1,cpos-1);
            cs:=copy(s,cpos,length(s)-cpos+1);
            co:=0;
            for j:=length(s1) downto 1 do
            begin
                r:=ord(s1[j])-64;
                for q:=1 to length(s1)-j do
                    r:=r*26;
                co:=co+r;
            end;
            Str(co,s2);
            ans[i]:='R'+cs+'C'+s2;
        end;
    end;
    for i:=1 to n do
        Writeln(ans[i]);
end.