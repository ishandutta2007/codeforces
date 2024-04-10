month, day = list(map(int, input().split()))
months = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
fs = 7 - day + 1
counter = 1
while fs + 7 <= months[month - 1]:
    counter += 1
    fs += 7
if (fs != months[month - 1]):
    counter += 1
print(counter)