program task_4;

{$apptype console r+ q+}
const nmax = 101000;
var Z,Next,Free: array[1..nmax*10]of integer;
    Head,cnt,mn: array[1..nmax]of integer;
    have: array[1..nmax]of boolean;
    n,m,i,j,len,lf,x,xx: integer;
    c: char;
    f: boolean;
begin
//assign(input,'input.txt');reset(input);
//assign(output,'output.txt');rewrite(output);
  lf:=nmax*10;
  for i:=1 to nmax*10 do
    Free[i]:=i;
  for i:=1 to nmax do begin
    Have[i]:=false;
    cnt[i]:=0;
  end;
  readln(n,m);
  for i:=1 to m do begin
    readln(c,xx);
    x:=xx;
    if (c = '-')then begin
      if (not Have[xx])then begin
        writeln('Already off');
        continue;
      end;
      j:=Head[xx];
      while (j<>-1)do begin
        cnt[z[j]]:=0;
        inc(lf);
        Free[lf]:=j;
        j:=Next[j];
      end;
      Head[xx]:=-1;
      Have[xx]:=false;
      writeln('Success');
    end else begin
      if (Have[xx])then begin
        writeln('Already on');
        continue;
      end;
      len:=0;
      for j:=2 to round(sqrt(x)) do
        if (x mod j=0)then begin
          inc(len);
          mn[len]:=j;
          while (x mod j =0)do x:=x div j;
        end;
      if (x>1)then begin
        inc(len);
        mn[len]:=x;
      end;
      f:=true;
      for J:=1 to len do
        if (cnt[mn[j]]<>0)then begin
          writeln('Conflict with ',cnt[mn[j]]);
          f:=false;
          break;
        end;
      if (not f)then continue;
      writeln('Success');
      Head[xx]:=-1;
      for j:=1 to len do begin
        len:=Free[lf];dec(lf);
        Next[len]:=Head[xx];
        Head[xx]:=len;
        Z[len]:=mn[j];
        cnt[mn[j]]:=xx;
      end;
      Have[xx]:=true;
    end;
  end;
end.