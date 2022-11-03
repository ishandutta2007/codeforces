Uses SysUtils;
type Tbox = record
  ml,n,por:integer;
end;
var
  a:array[1..1000]of Tbox;
  n,l,i,j,c:integer;
  b:boolean;
  k:tbox;
  
begin
  read(n);
  l:=0;
  for i:=1 to n do begin
    read(c);
    b:=false;
    for j:=1 to l do
      if a[j].ml=c then begin inc(a[j].n); b:=true; break; end;
    if not b then begin inc(l); a[l].ml:=c; a[l].por:=i; a[l].n:=1; end;
  end;
  if (l>3)or((l=2)and(n<>2)) then writeln('Unrecoverable configuration.') else
    if l=1 then writeln('Exemplary pages.') else begin
      for i:=1 to l-1 do
        for j:=i+1 to l do
          if a[j].ml<a[i].ml then begin k:=a[i]; a[i]:=a[j]; a[j]:=k; end;
      if l=2 then begin
        l:=a[2].ml-a[1].ml;
        if l mod 2<>0 then begin writeln('Unrecoverable configuration.'); halt; end;
        l:=l div 2;
        c:=2;
        j:=1;
      end else begin
        if a[2].n<>n-2 then begin writeln('Unrecoverable configuration.'); halt; end;
        c:=a[3].ml-a[2].ml;
        j:=a[2].ml-a[1].ml;
        if c<>j then begin writeln('Unrecoverable configuration.'); halt; end;
        l:=a[3].ml-a[2].ml;
        c:=3;
        j:=1;
      end;
      write(inttostr(l)+' ml. from cup #');
      if a[c].ml<a[j].ml then begin n:=c; c:=j; j:=n; end;
      write(inttostr(a[j].por)+' to cup #'+inttostr(a[c].por)+'.');
    end;
end.