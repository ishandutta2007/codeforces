im = int(input())

best_steps = 0
best_length = 0

def rec(m, steps, substracted):
    global best_steps, best_length 
    if m == 0:
        if steps > best_steps:
            best_steps = steps
            best_length = substracted
        elif steps == best_steps:
            best_length = max(best_length, substracted)
        return

    a = 1
    while (a + 1)**3 <= m:
        a += 1

    rec(m - a**3, steps + 1, substracted + a**3)

    if a - 1 != 0:
        rec(a**3-1-(a-1)**3, steps + 1, substracted + (a-1)**3)

rec(im, 0, 0)
print(best_steps, best_length)