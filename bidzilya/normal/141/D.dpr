{$APPTYPE CONSOLE}
{$M 16000000}
const nmax = 200010;
var x,dd,tt,pp,nn,L,i,j,buf,n,m,len:integer;
    Head,v,p,s,os,pr,d,jump,op:array[1..2*nmax]of integer;
    Next,W,T:array[1..4*nmax]of integer;

procedure qsort(l,r:integer);
begin
  i:=l; j:=r; x:=v[i+random(j-i+1)];
  repeat
    while (v[i]<x)do inc(i);
    while (v[j]>x)do dec(j);
    if (i<=j)then begin
      buf:=op[p[i]]; op[p[i]]:=op[p[j]]; op[p[j]]:=buf;
      buf:=p[i]; p[i]:=p[j]; p[j]:=buf;
      buf:=v[i]; v[i]:=v[j]; v[j]:=buf;
      inc(i); dec(j);
    end;
  until (i>j);
  if (i<r)then qsort(i,r);
  if (j>l)then qsort(l,j);
end;

procedure down(ind:integer);
var md:integer;
begin
  while (ind*2<=len)do begin
    md:=ind*2;
    if (md+1<=len)and(d[s[md+1]]<d[s[md]])then inc(md);
    if (d[s[md]]<d[s[ind]])then begin
      buf:=s[md]; s[md]:=s[ind]; s[ind]:=buf;
      buf:=os[s[md]]; os[s[md]]:=os[s[ind]]; os[s[ind]]:=buf;
      ind:=md;
    end else exit;
  end;
end;

procedure up(ind:integer);
var md:integer;
begin
  while (ind>1)do begin
    md:=ind div 2;
    if (d[s[md]]>d[s[ind]])then begin
      buf:=s[md]; s[md]:=s[ind]; s[ind]:=buf;
      buf:=os[s[md]]; os[s[md]]:=os[s[ind]]; os[s[ind]]:=buf;
      ind:=md;
    end else exit;
  end;
end;

procedure go;
var ans:array[1..nmax]of integer;
    k,i:integer;
begin
  k:=0;
  i:=n;
  while (i<>-1)do begin
    if (jump[i]<>0)then begin
      inc(k);
      ans[k]:=jump[i];
    end;
    i:=pr[i];
  end;
  writeln(k);
  for i:=k downto 1 do write(ans[i],' ');
end;

begin
 // assign(input,'input.txt');reset(input);
 // assign(output,'output.txt');rewrite(output);
  randomize;
  readln(nn,L);
  n:=1; v[1]:=0; p[1]:=1; op[1]:=1;
  m:=0;
  for i:=1 to 2*nmax do Head[i]:=-1;
  for i:=1 to nn do begin
    readln(x,dd,tt,pp);
    inc(m);
    if (x-pp<0)or(dd<=tt)then continue;
    inc(n);
    v[n]:=x-pp;
    p[n]:=n;
    op[n]:=n;
    inc(n);
    v[n]:=x+dd;
    p[n]:=n;
    op[n]:=n;

    Next[m]:=Head[n-1];
    Head[n-1]:=m;
    T[m]:=n;
    W[m]:=tt+pp;
    //writeln(v[n-1],' ',v[n],' ',w[m]);
  end;
  inc(n);
  v[n]:=L; p[n]:=n; op[n]:=n;
  qsort(1,n);
  for i:=1 to n do begin
    if (i<>n)then begin
      inc(m);
      Next[m]:=Head[p[i]];
      Head[p[i]]:=m;
      T[m]:=p[i+1];
      W[m]:=v[i+1]-v[i];
      //writeln(v[i],' ',v[i+1],' ',w[m]);
    end;

    if (i<>1)then begin
      inc(m);
      Next[m]:=Head[p[i]];
      Head[p[i]]:=m;
      T[m]:=p[i-1];
      W[m]:=v[i]-v[i-1];
     // writeln(v[i],' ',v[i-1],' ',w[m]);
    end;
  end;
  for i:=1 to n do begin
    d[i]:=maxint;
    s[i]:=i;
    os[i]:=i;
    pr[i]:=-1;
    jump[i]:=0;
  end;
  len:=n;
  d[1]:=0;
  while (true)do begin
    if (len=0)then break;
    pp:=s[1];
    s[1]:=s[len];
    os[s[1]]:=1;
    dec(len);
    down(1);
    i:=Head[pp];
    while (i<>-1)do begin
      if (d[pp]+w[i]<d[T[i]])then begin
        d[T[i]]:=d[pp]+w[i];
        pr[T[i]]:=pp;
        if (w[i]<>abs(v[op[T[i]]]-v[op[pp]]))then jump[T[i]]:=i else
          jump[T[i]]:=0;
        up(os[T[i]]);
      end;
      i:=Next[i];
    end;
  end;
  writeln(d[n]);
  go;
end.