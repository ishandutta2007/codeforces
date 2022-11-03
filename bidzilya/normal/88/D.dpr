type Tbox = record
    name,typ:string;
    znak:integer;
end;

var
    arr:array[0..101]of Tbox;
    n,i,j,k,znak,n1,n2,amp:integer;
    s,tmp,name:String;
    
procedure get_str(d:integer);
var
    j:integer;
begin
    if d=1 then j:=9;
    if d=2 then j:=8;
    while s[j]='&' do 
      begin
        inc(j);
        inc(amp);
      end;
    while (j<=length(s))and(s[j]<>'*')and(s[j]<>' ') do 
      begin
        tmp:=tmp+s[j];
        inc(j);
      end;
    while (j<=length(s))and(s[j]='*') do 
      begin
        inc(j);
        inc(znak);
      end;
    if d=1 then 
      begin
        inc(j);
        name:=copy(s,j,length(s)-j+1);
      end;
end;

begin
    arr[0].name:='void';
    arr[0].typ:='void';
    arr[0].znak:=0;
    k:=0;
    readln(n);
    for i:=1 to n do 
      begin
        readln(s);
        if copy(s,1,7)='typedef' then 
          begin
            znak:=0;
            amp:=0;
            tmp:='';
            name:='';
            get_str(1);
            n1:=-1;
            n2:=-1;
            for j:=0 to k do 
              begin
                if arr[j].name=tmp then n1:=j;
                if arr[j].name=name then n2:=j; 
              end;
            if n1=-1 then tmp:='errtype' else
                begin
                  tmp:=arr[n1].typ;
                  znak:=arr[n1].znak+znak;
                end;
            if n2=-1 then
              begin
                inc(k);
                n2:=k;
              end;
            if amp>znak then tmp:='errtype' else znak:=znak-amp;
            if tmp='errtype' then znak:=0;
            arr[n2].typ:=tmp;
            arr[n2].name:=name;
            arr[n2].znak:=znak;
        end else 
          begin
            znak:=0;
            amp:=0;
            tmp:='';
            get_str(2);
            n1:=-1;
            for j:=0 to k do
              if arr[j].name=tmp then begin n1:=j; break; end;
            if (n1=-1)or(arr[n1].typ='errtype') then begin writeln('errtype'); continue; end;
            znak:=arr[n1].znak+znak;
            if amp>znak then begin writeln('errtype'); continue; end else znak:=znak-amp;
            write(arr[n1].typ);
            for j:=1 to znak do write('*');
            writeln('');
          end;
     end;
end.