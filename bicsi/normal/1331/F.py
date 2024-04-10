s = """

Hydrogen	H	Niobium	Nb	Thallium	Tl
Helium	He	Molybdenum	Mo	Lead	Pb
Lithium	Li	Technetium	Tc	Bismuth	Bi
Beryllium	Be	Ruthenium	Ru	Polonium	Po
Boron	B	Rhodium	Rh	Astatine	At
Carbon	C	Palladium	Pd	Radon	Rn
Nitrogen	N	Silver	Ag	Francium	Fr
Oxygen	O	Cadmium	Cd	Radium	Ra
Fluorine	F	Indium	In	Actinium	Ac
Neon	Ne	Tin	Sn	Thorium	Th
Sodium	Na	Antimony	Sb	Protactinium	Pa
Magnesium	Mg	Tellurium	Te	Uranium	U
Aluminum	Al	Iodine	I	Neptunium	Np
Silicon	Si	Xenon	Xe	Plutonium	Pu
Phosphorus	P	Cesium	Cs	Americium	Am
Sulfur	S	Barium	Ba	Curium	Cm
Chlorine	Cl	Lanthanum	La	Berkelium	Bk
Argon	Ar	Cerium	Ce	Californium	Cf
Potassium	K	Praseodymium	Pr	Einsteinium	Es
Calcium	Ca	Neodymium	Nd	Fermium	Fm
Scandium	Sc	Promethium	Pm	Mendelevium	Md
Titanium	Ti	Samarium	Sm	Nobelium	No
Vanadium	V	Europium	Eu	Lawrencium	Lr
Chromium	Cr	Gadolinium	Gd	Rutherfordium	Rf
Manganese	Mn	Terbium	Tb	Dubnium	Db
Iron	Fe	Dysprosium	Dy	Seaborgium	Sg
Cobalt	Co	Holmium	Ho	Bohrium	Bh
Nickel	Ni	Erbium	Er	Hassium	Hs
Copper	Cu	Thulium	Tm	Meitnerium	Mt
Zinc	Zn	Ytterbium	Yb	Darmstadtium	Ds
Gallium	Ga	Lutetium	Lu	Roentgenium	Rg
Germanium	Ge	Hafnium	Hf	Copernicium	Cn
Arsenic	As	Tantalum	Ta	Nihonium	Nh
Selenium	Se	Tungsten	W	Flerovium	Fl
Bromine	Br	Rhenium	Re	Moscovium	Mc
Krypton	Kr	Osmium	Os	Livermorium	Lv
Rubidium	Rb	Iridium	Ir	Tennessine	Ts
Strontium	Sr	Platinum	Pt	Oganesson	Og
Yttrium	Y	Gold	Au
Zirconium	Zr	Mercury	Hg
"""
elems = []
for idx, token in enumerate(s.split()):
  if idx % 2 == 1:
    elems.append(token.upper())


def check(s):
  if not s:
    return True
  for idx in range(len(s)):
    if s[idx:] in elems and check(s[:idx]):
      return True
  return False

s = input()
if check(s):
  print("YES")
else:
  print("NO")