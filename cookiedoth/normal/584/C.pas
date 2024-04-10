program Program56;
var
    s1,s2:array[1..100000] of Char;
    s3:array[1..100000] of Boolean;
    s4:array[1..100000] of Integer;
    n,t,i,kr,knr,min,max:Integer;
    j:Char;
    f40,f41,f42,t40,t41:Integer;
begin
    Readln(n,t);
    for i:=1 to n do
        Read(s1[i]);
    Readln;
    for i:=1 to n do
        Read(s2[i]);
    kr:=0;
    knr:=0;
    for i:=1 to n do
    begin
        if s1[i]=s2[i] then
        begin
            s3[i]:=true;
            inc(kr); 
        end
        else
        begin
            s3[i]:=false;
            inc(knr);
        end;
    end;   
    min:=knr;
    max:=2*knr+2*kr;
    if (min>2*t) or (2*t>max) then
    begin
        Writeln('-1');
        Halt(0);
    end;
    f40:=0; f41:=0; f42:=0; t40:=0; t41:=0;
    if (knr mod 2)=1 then 
    begin
        inc(f40);
        dec(knr);
        dec(t);
    end;
    knr:=knr div 2;
    if (t>=knr*2) then
    begin
        inc(f40,knr*2);
        f41:=0;
        f42:=0;
        t40:=t-knr*2;
        t41:=kr-t40;
    end;
    if (t<knr*2) then
    begin
        inc(f40,(t-knr)*2);
        f41:=2*knr-t;
        f42:=f41;
        t40:=0;
        t41:=kr;
    end;
    for i:=1 to n do
    begin
        if s3[i]=false then
        begin
            if f40>0 then begin s4[i]:=0; dec(f40); end
            else begin
            if f41>0 then begin s4[i]:=1; dec(f41); end
            else if f42>0 then begin s4[i]:=2; dec(f42) end; end;
        end;
        if s3[i]=true then
        begin
            if t40>0 then begin s4[i]:=0; dec(t40); end
            else begin s4[i]:=1; dec(t41); end;
        end;
    end;
    for i:=1 to n do
    begin
        if (s3[i]=true) and (s4[i]=1) then Write(s1[i]);
        if (s3[i]=false) and (s4[i]=1) then Write(s1[i]);
        if (s3[i]=false) and (s4[i]=2) then Write(s2[i]);
        if (s4[i]=0) then
        begin
            for j:='a' to 'z' do
            begin
                if (j<>s1[i]) and (j<>s2[i]) then
                begin
                    Write(j);
                    Break;
                end;
            end;
        end;
    end;
end.
//t40-, t41-