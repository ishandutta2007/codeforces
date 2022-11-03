type Tbox1 = record
    x,r:integer;
end;
var
    a,n,m,i,j,k,x,y:integer;
    r:real;
    c:array[1..10000]of Tbox1;
    ans:array[1..10000]of integer;
    mp:array[-21000..21000,1..2]of integer;
    
begin
   // assign(input,'input.txt');
   // reset(input);
    for i:=-21000 to 21000 do for j:=1 to 2 do mp[i,j]:=-1;
    read(n);
    for i:=1 to n do begin
      read(c[i].x,c[i].r);
      ans[i]:=-1;
      for j:=c[i].x-c[i].r to c[i].x+c[i].r do
        if mp[j,1]=-1 then mp[j,1]:=i else mp[j,2]:=i;
    end;
    read(m);
    a:=0;
    for i:=1 to m do begin
      read(x,y);
      if mp[x,1]<>-1 then begin
        j:=mp[x,1];
        r:=sqrt(sqr(c[j].x-x)+sqr(y));
        if r<=c[j].r then begin
          ans[j]:=i;
          inc(a);
          for k:=c[j].x-c[j].r+1 to c[j].x+c[j].r-1 do
              mp[k,1]:=-1;
          k:=c[j].x-c[j].r;
          if mp[k,2]=j then mp[k,2]:=-1;
          if mp[k,1]=j then begin
            mp[k,1]:=mp[k,2];
            mp[k,2]:=-1;
          end;
          k:=c[j].x+c[j].r;
          if mp[k,2]=j then mp[k,2]:=-1;
          if mp[k,1]=j then begin
            mp[k,1]:=mp[k,2];
            mp[k,2]:=-1;
          end;
        end;
        if mp[x,1]<>-1 then begin
          j:=mp[x,1];
          r:=sqrt(sqr(c[j].x-x)+sqr(y));
          if r<=c[j].r then begin
            ans[j]:=i;
            inc(a);
            for k:=c[j].x-c[j].r+1 to c[j].x+c[j].r-1 do
              mp[k,1]:=-1;
            k:=c[j].x-c[j].r;
            if mp[k,2]=j then mp[k,2]:=-1;
            if mp[k,1]=j then begin
              mp[k,1]:=mp[k,2];
              mp[k,2]:=-1;
            end;
            k:=c[j].x+c[j].r;
            if mp[k,2]=j then mp[k,2]:=-1;
            if mp[k,1]=j then begin
              mp[k,1]:=mp[k,2];
              mp[k,2]:=-1;
            end;
          end;
        end;
      end;
    end;
    writeln(a);
    for i:=1 to n do
      write(ans[i],' ');
end.