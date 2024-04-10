program task_5;

{$APPTYPE CONSOLE}
uses SysUtils;
const nmax = 100000;
      mmax = 10000;
      maxint = 1000000;
var s,t,v,rt: string;
    i,nn,j,l,r,ans: integer;
    found: boolean;
    p: array[1..nmax+mmax]of integer;
    min,max: array[1..mmax]of integer;
begin
//assign(input,'input.txt');reset(input);
//assign(output,'output.txt');rewrite(output);
  readln(t);
  rt:='';
  for i:=length(t)downto 1 do rt:=rt+t[i];
  ans:=0;
  readln(nn);
  for nn:=1 to nn do begin
    readln(s);

    found:= false;

    v:=s+'#'+t;
    p[1]:=length(v);
    r:=0;
    for i:=2 to length(v)do begin
      if (i<=r)then begin
        p[i]:=r-i+1;
        if (p[i-l+1]<p[i])then
          p[i]:=p[i-l+1];
      end else
        p[i]:=0;
      while (i+p[i]<=length(v))and(v[i+p[i]]=v[p[i]+1])do inc(p[i]);
      if (i+p[i]-1>r)then begin
        r:=i+p[i]-1;
        l:=i;
      end;
    end;
    for i:=1 to length(s)do min[i]:=maxint;
    for i:=length(s)+2 to length(v)do begin
        j:=p[i];
        r:=i-length(s)-1;
        if (r<min[j])then min[j]:=r;
      end;
    v:='';
    for i:=length(s)downto 1 do v:=v+s[i];
    v:=v+'#'+rt;
    p[1]:=length(v);
    r:=0;
    for i:=2 to length(v)do begin
      if (i<=r)then begin
        p[i]:=r-i+1;
        if (p[i-l+1]<p[i])then
          p[i]:=p[i-l+1];
      end
      else
        p[i]:=0;
      while (i+p[i]<=length(v))and(v[i+p[i]]=v[p[i]+1])do inc(p[i]);
      if (i+p[i]-1>r)then begin
        l:=i;
        r:=i+p[i]-1;
      end;
    end;
    for i:=1 to length(s)do max[i]:=-maxint;
    for i:=length(s)+2 to length(v)do begin
        j:=p[i];
        r:=length(t)-(i-length(s)-1)+1;
        if (r>max[j])then max[j]:=r;
      end;
    for i:=length(s)-1 downto 1 do begin
      if (min[i+1]<min[i])then min[i]:=min[i+1];
      if (max[i+1]>max[i])then max[i]:=max[i+1];
    end;
    for i:=1 to length(s)-1 do begin
      j:=length(s)-i;
      if (min[i]<max[j]-length(s)+2)then begin
        found:=true;
        break;
      end;
    end;
    if (found)then inc(ans);
  end;
  write(ans);
end.