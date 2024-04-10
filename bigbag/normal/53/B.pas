var h, w, h1, w1, maxs, maxh, answ : int64;
    x : real;
begin
    read(h, w);
    maxs := 0;
    maxh := 0;
    h1 := 1;
    while h1 <= h do begin
        w1 := trunc(h1 / 0.8);
        inc(w1);
        if (w1 > w) then begin
            w1 := w;
        end;
        x := h1 / w1;
        //writeln(h1, ' ', w1);
        if (x >= 0.8) and (x <= 1.25) then begin            
            if (maxs < w1 * h1) or (maxs = w1 * h1) and (h1 > maxh) then begin
                maxs := w1 * h1;
                maxh := h1;
                answ := w1;
            end;
        end else if w1 <> 1 then
        begin
          dec(w1);
            x := h1 / w1;
          //writeln(h1, ' ', w1);
            if (x >= 0.8) and (x <= 1.25) then begin            
                if (maxs < w1 * h1) or (maxs = w1 * h1) and (h1 > maxh) then begin
                    maxs := w1 * h1;
                    maxh := h1;
                    answ := w1;
                end;
            end;
        end;
        h1 := h1 *2;
    end;
    w1 := 1;
    while w1 <= w do begin
        h1 := trunc(w1 * 1.25);
        if (h1 > h) then begin
            h1 := h;
        end;
        x := h1 / w1;
        if (x >= 0.8) and (x <= 1.25) then begin
            if (maxs < w1 * h1) or (maxs = w1 * h1) and (h1 > maxh) then begin
                maxs := w1 * h1;
                maxh := h1;
                answ := w1;
            end;
        end;
        w1 := w1 * 2;
    end;
    write(maxh, ' ', answ);
end.