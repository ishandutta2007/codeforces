var
s,s1:string;
ch:array[1..200001] of char;
int:array[1..200001] of integer;
c:char;
o,i,j:integer;
b:boolean;
begin  
    c:='#';
    for i:=1 to 200001 do ch[i]:='#';
    o:=0;
    readln(s);
    for i:=1 to length(s) do
    begin
        if s[i]=c then inc(int[o])
        else
        begin
            inc(o);
            c:=s[i];
            ch[o]:=c;
            int[o]:=1;
        end;
    end;
    s1:='';
    for i:=1 to o do
    begin
        for j:=1 to int[i] do
        begin
            if (j mod 2)=0 then
            begin
                b:=true;
                if (ch[i]<>'a') and (ch[i+1]<>'a') and (b) then begin s1:=s1+'a'; b:=false; end;
                if (ch[i]<>'b') and (ch[i+1]<>'b') and (b) then begin s1:=s1+'b'; b:=false; end;
                if (ch[i]<>'c') and (ch[i+1]<>'c') and (b) then begin s1:=s1+'c'; b:=false; end;
            end
            else s1:=s1+ch[i];
        end;
    end;
    writeln(s1);
end.