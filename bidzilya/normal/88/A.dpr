var
  s,c1,c2,c3:string;
  n1,n2,n3:integer;
  
function pro(k:string):integer;
begin
  if k[1]='C' then result:=1 else
    if k[1]='D' then result:=3 else
      if k[1]='E' then result:=5 else
        if k[1]='F' then result:=6 else
          if k[1]='G' then result:=8 else
            if k[1]='A' then result:=10 else
              if k[1]='B' then result:=11 else
                if k[1]='H' then result:=12;
  if (length(k)>1)and(k[2]='#') then result:=result+1;                
end;

procedure prov(a,b,c:integer);
var ar,br:integer;
begin
  ar:=b-a;
  br:=c-b;
  if ar<0 then ar:=b-a+12;
  if br<0 then br:=c-b+12;
  if (ar=4)and(br=3)then begin writeln('major'); halt; end;
  if (ar=3)and(br=4)then begin writeln('minor'); halt; end;
end;

begin
  readln(s);
  c1:=copy(s,1,pos(' ',s)-1);
  delete(s,1,pos(' ',s));
  c2:=copy(s,1,pos(' ',s)-1);
  delete(s,1,pos(' ',s));
  c3:=s;
  n1:=pro(c1);
  n2:=pro(c2);
  n3:=pro(c3);
  prov(n1,n2,n3);
  prov(n1,n3,n2);
  prov(n2,n1,n3);
  prov(n2,n3,n1);
  prov(n3,n1,n2);
  prov(n3,n2,n1);
  writeln('strange');
end.