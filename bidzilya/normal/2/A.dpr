uses SysUtils;
var
    name:array[0..1000]of string;
    score:array[1..1000,0..1000]of integer;
    i,j,n,mx,k,tmp,l:integer;
    s:string;
    bol:boolean;
begin
    readln(n);
    k:=0;
    for i:=1 to n do
        score[i,0]:=0;
        
    for i:=1 to n do begin
        readln(s);
        j:=1;
        name[0]:='';
        while s[j]<>' ' do begin name[0]:=name[0]+s[j]; inc(j); end;
        inc(j);
        tmp:=strtoint(copy(s,j,length(s)+1-j));
        bol:=false;
        for j:=1 to k do
            if name[j]=name[0] then 
              begin
                for l:=1 to n do
                    score[l,i]:=score[l,i-1];
                score[j,i]:=score[j,i]+tmp;
                bol:=true;
                break;
              end;
        if not bol then 
          begin
            for l:=1 to n do
                score[l,i]:=score[l,i-1];
            inc(k);
            name[k]:=name[0];
            score[k,i]:=tmp;
          end;
     end;
     mx:=-maxint;
     for i:=1 to k do
        if score[i,n]>mx then mx:=score[i,n];
     
     l:=maxint;
     s:='';
     for i:=1 to k do
        if score[i,n]=mx then
            for j:=1 to n do
                if (score[i,j]>=mx)and(j<l)then 
                  begin
                    l:=j;
                    s:=name[i];
                    break;
                  end;
     writeln(s);
end.