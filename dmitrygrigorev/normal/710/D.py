def nod(a, b):
    if b == 0:
        return a, 1, 0
    else:
        answer, x, y = nod(b, a % b)
        x1 = y
        y1 = x - (a // b) * y
        return answer, x1, y1


a1, b1, a2, b2, l, r = list(map(int, input().split()))
coeff = b1
b1, b2, l, r = b1 - coeff, b2 - coeff, max(l - coeff, 0), r - coeff
l = max(b2, l)
od, x1, y1 = nod(a1, -a2)
if b2 % od != 0 or l > r:
    print(0)
else:    
    x1, y1 = x1 * (b2 // od), y1 * (b2 // od)
    result = x1 * a1 
    raznitsa = a1 * a2 // nod(a1, a2)[0]
    otvet = 0
    if result < l:
        vsp = (l - result) // raznitsa
        if (l - result) % raznitsa != 0:
            vsp += 1
        result += vsp * raznitsa
    if result > r:
        vsp = (result - r) // raznitsa
        if (result - r) % raznitsa != 0:
            vsp += 1        
        result -= vsp * raznitsa      
    if result <= r and result >= l:
        otvet += 1
        otvet += abs(result - r) // raznitsa
        otvet += abs(result - l) // raznitsa
    print(otvet)    
    # 3 * (- 54) + 81 =