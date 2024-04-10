s = {
    "Tetrahedron": 4,
    "Cube": 6,
    "Octahedron": 8,
    "Dodecahedron": 12,
    "Icosahedron": 20
}
n = input()
sum = 0
for i in xrange(n):
    sum += s[raw_input()]

print sum